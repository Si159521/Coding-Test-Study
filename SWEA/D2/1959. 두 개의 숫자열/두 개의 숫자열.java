/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		//System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
		  //입력
            int n=sc.nextInt();
            int m=sc.nextInt();
            int[] nArray= new int[n];
            int[] mArray = new int[m];
            for(int i=0;i<n;i++){
                nArray[i]=sc.nextInt();
            }
            for(int i=0;i<m;i++){
                mArray[i]=sc.nextInt();
            }

            //알고리즘
            //마주보는 수끼리 곱한 값의 합이 가장 큰 경우를 출력
            //0번인덱스부터 n-m까지 이동하며 합을 구한다
            int max=Integer.MIN_VALUE;

            for(int i=0;i<=Math.abs(m-n);i++){
                int sum=0;
                for(int j=0;j<Math.min(n,m);j++){
                    if(n>m){
                        sum+=mArray[j]*nArray[i+j];
                    }else{
                        sum+=nArray[j]*mArray[i+j];
                    }
                }
                max=Math.max(sum,max);
            }

            //출력
            System.out.printf("#%d %d\n", test_case, max);
		}
	}
}