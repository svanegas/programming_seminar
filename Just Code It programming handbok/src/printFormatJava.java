import java.util.Calendar;
import java.util.Locale;

public class Main {
    
    public static void main(String[] args) {
      long n = 461012;
      System.out.format("%d%n", n);      //  -->  "461012"
      System.out.format("%08d%n", n);    //  -->  "00461012"
      System.out.format("%+8d%n", n);    //  -->  " +461012"
      System.out.format("%,8d%n", n);    // -->  " 461,012"
      System.out.format("%+,8d%n%n", n); //  -->  "+461,012"
      
      double pi = Math.PI;

      System.out.format("%f%n", pi);       // -->  "3.141593"
      System.out.format("%.3f%n", pi);     // -->  "3.142"
      System.out.format("%10.3f%n", pi);   // -->  "     3.142"
      System.out.format("%-10.3f%n", pi);  // -->  "3.142"
      System.out.format(Locale.ENGLISH,
                        "%-10.4f%n%n", pi); // -->  "3.1416"

      Calendar c = Calendar.getInstance();
      //  -->  "September 3, 2014"
      System.out.format("%tB %te, %tY%n", c, c, c);
      //  -->  "3:21 am"
      System.out.format("%tl:%tM %tp%n", c, c, c);
      //  -->  "09/03/14"
      System.out.format("%tD%n", c);    
    }
}