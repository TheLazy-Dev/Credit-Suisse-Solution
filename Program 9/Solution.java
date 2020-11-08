import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the organizingContainers function below.
    static String organizingContainers(int[][] container) {
         int c[] = new int[container.length];
        int t[] = new int[container.length];

        for (int i = 0; i < container.length; i++) {
            for (int j = 0; j < container[0].length; j++) {

                c[i] += container[i][j];
                t[j] += container[i][j];
            }
        }

        Arrays.sort(c);
        Arrays.sort(t);

        if (Arrays.equals(c, t)) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        String answer="";
        while(q-->0)
        {
            int n = in.nextInt();
            int[][] M = new int[n][n];
            for(int i=0; i < n; i++)
                for(int j=0; j < n; j++)
                    M[i][j] = in.nextInt();
            String result= organizingContainers(M);
            if (answer.equals(""))
            {
                answer= result;
            }
            else
            {
                answer= answer + ","+result;
            }
        }

        // Do not remove below line
        System.out.println(answer);
        // Do not print anything after this line

        scanner.close();
    }
}
