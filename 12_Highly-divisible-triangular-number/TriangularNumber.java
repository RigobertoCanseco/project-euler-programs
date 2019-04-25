import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;


public class TriangularNumber {


    public static void main(String[] args) {
        System.out.println("Hi!");

        long c = 0;
        int n = 0;
        int i = 1;
        while( c <= 500) {
            n += i++;
            int finalN = n;
            List<Integer> d = new ArrayList<>();
            //System.out.print(n + " | ");
            IntStream.range(1, (int) (Math.floor(Math.sqrt(n))+1)).forEach(e -> {
                if(finalN %e == 0){
                    d.add(e);
                    d.add(finalN/e);
                }
            }); //.filter(s -> finalN %s == 0 ).count();
            //d.stream().sorted(Comparator.naturalOrder()).forEach(v -> System.out.print(v + " "));
            //System.out.println(" = " + d.size());
            c = d.size();
        }
        System.out.println( n + " " +c);
    }
}
