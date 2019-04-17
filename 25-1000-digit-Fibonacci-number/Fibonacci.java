import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.stream.Stream;

public class Fibonacci {
    private static <T> Stream<T> reverse(Stream<T> stream) {
        LinkedList<T> stack = new LinkedList<>();
        stream.forEach(stack::push);
        return stack.stream();
    }

    public static String sum(String s, String s2){
        Stream<Integer> sl = reverse(s.chars().mapToObj(c -> c - '0'));
        Stream<Integer> sl2 = reverse(s2.chars().mapToObj(c -> c - '0'));
        Iterator<Integer> iter1 = sl.iterator(), iter2 = sl2.iterator();
        StringBuilder c = new StringBuilder();
        int v = 0;
        int r = 0;
        int a = 0;
        while(true) {
            if(iter1.hasNext() && iter2.hasNext()){
                v = iter1.next() + iter2.next() + a;
                r = v %10;
                a = v /10;
                c.append(r);
            }else if(!iter1.hasNext() && iter2.hasNext()){
                v = iter2.next() + a;
                r = v %10;
                a = v /10;
                c.append(r);
            }else if(!iter2.hasNext() && iter1.hasNext()){
                v = iter1.next() + a;
                r = v %10;
                a = v /10;
                c.append(r);
            }else{
                if(a != 0)
                    c.append(a);
                break;
            }
        }
        return new StringBuilder(c).reverse().toString();
    }

    public static void main(String[] args) throws IOException {
        String f = "1";
        String fi = "1";
        String ft = "";
        int i = 2;
        while(ft.length() != 1000){
            ft = sum(f, fi);
            f = fi;
            fi = ft;
            i++;
        }
        System.out.println("Number:" + ft);
        System.out.println("Position:" + i);
    }
}
