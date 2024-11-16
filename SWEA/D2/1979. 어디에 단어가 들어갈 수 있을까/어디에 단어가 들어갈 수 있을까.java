import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
		 	//입력
            int n= sc.nextInt(); //n*n크기의 퍼즐판
            int k = sc.nextInt(); //단어길이
            int[][] puzzle = new int[n][n]; //0과 1로 표현된 퍼즐판
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    puzzle[i][j]=sc.nextInt();
                }
            }
            
            //알고리즘
              int possible=0;

           // 가로 탐색
            for (int i = 0; i < n; i++) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (puzzle[i][j] == 1) {
                        count++;
                    } else {
                        if (count == k) {
                            possible++;
                        }
                        count = 0; // 초기화
                    }
                }
                if (count == k) { // 행 끝에서 마지막 연속된 1 검사
                    possible++;
                }
            }

            // 세로 탐색
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (puzzle[i][j] == 1) {
                        count++;
                    } else {
                        if (count == k) {
                            possible++;
                        }
                        count = 0; // 초기화
                    }
                }
                if (count == k) { // 열 끝에서 마지막 연속된 1 검사
                    possible++;
                }
            }
            
            //출력
            System.out.printf("#%d %d\n", test_case, possible);
            
		}
	}
}