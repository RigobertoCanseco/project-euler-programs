import os
from os import listdir
from os.path import isfile, join
import requests
import feedparser
from bs4 import BeautifulSoup
import datetime


def last_problem():
    for entry in feedparser.parse('https://projecteuler.net/rss2_euler.xml').entries:
        if entry.title.find('Problem') == 0:
            return int(entry.title[8:])


def save_in_file(link, title, problem_id, content, dir='_posts/'):
    n = dir + datetime.datetime.now().strftime('%Y-%m-%d') + '_' + problem_id + '-' \
        + title.lower().replace(' ', '-').replace('/', '-') + '.md'
    f = open(n, 'w')
    f.write('---\nlayout: post\nmathjax: true\n---\n**' + 'Problem ' + problem_id + '**  \n' + '[' + link + ']('
            + link + ')' + '\n\n' + content + '\n---\n')
    f.close()
    return n


def get_problem(id):
    try:
        link = 'https://projecteuler.net/problem=' + id
        page = requests.get(link)
        content = requests.get('https://projecteuler.net/minimal=' + id)
        soup = BeautifulSoup(page.text, 'html.parser')
        return save_in_file(link, soup.find('h2').text, id, content.text)
    except Exception as e:
        print('Error:', e)


def get_all():
    p = last_problem()

    for i in range(1, p):
        if i < 10:
            n = '0'+str(i)
        else:
            n = str(i)
        f = get_problem(n)
        print('Get problem:', i, '\tFile:', f)


def renames_files():
    files = [f for f in listdir('_posts_rm') if isfile(join('_posts_rm', f))]
    for i in files:
        os.rename('_posts_rm/' + i, '_posts_rm/' + i.replace('.md | tr _ -', '.md').replace('_', '-'))


if __name__ == '__main__':
    files = [f for f in listdir('_posts') if isfile(join('_posts', f))]
    for i in files:
        print('problems/' + i[11:])
