import requests
import feedparser
from bs4 import BeautifulSoup
import datetime
import re
import os
import base64


TOKEN = os.environ['TOKEN_GITHUB']
URL = 'https://api.github.com/repos/rigobertocanseco/project-euler-problems/contents/_posts/'
P_EULER = 'https://projecteuler.net/project/'


def last_problem():
    for entry in feedparser.parse('https://projecteuler.net/rss2_euler.xml').entries:
        if entry.title.find('Problem') == 0:
            return int(entry.title[8:])


def read_last_problem():
    file = open(file='last-problem.txt', mode='r')
    p = int(file.read())
    file.close()
    return p


def write_last_problem(p):
    file = open(file='last-problem.txt', mode='w')
    file.write(str(p))
    file.close()


if __name__ == '__main__':
    l = read_last_problem()
    f = last_problem()
    try:
        for i in range(l + 1, f):
            id = str(i)
            link = 'https://projecteuler.net/problem=' + id
            data = requests.get('https://projecteuler.net/minimal=' + id)
            clean_data = re.sub('"project/', P_EULER, data.text)
            name = datetime.datetime.now().strftime('%Y-%m-%d') + '-' + id + '-' + BeautifulSoup(requests.get(link).text
                ,'html.parser').find('h2').text.lower().replace(' ', '-').replace('/', '-') + '.md'
            content = '---\nlayout: post\nmathjax: true\n---\n**' + 'Problem ' + id + '**  \n' + '[' + link + '](' \
                      + link + ')' + '\n\n' + clean_data + '\n---\n'
            f = open('_posts/' + name, 'w')
            f.write(content)
            f.close()
            print('Create file', name)
            response = requests.put(URL + name, headers={
                'Accept': 'application/vnd.github.v3+json',
                'Content-Type': 'application/x-www-form-urlencoded',
                'Authorization': 'bearer ' + TOKEN
            }, json={
                'message': 'update file ' + name,
                'branch': 'gh-pages',
                'content': base64.b64encode(content.encode('ascii')).decode('utf-8')
            })
            print('Upload file', response)
            if response.status_code != 201:
                exit(-1)
            print('Finish, last problem ', i)
            write_last_problem(i)

    except Exception as e:
        print('Error: ', e)
        write_last_problem(i - 1)
