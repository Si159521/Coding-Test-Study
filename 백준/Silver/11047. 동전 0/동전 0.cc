#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; //동전 종류
	int k; //목표 금액
	int min=0;
	vector<int> value; //동전의 가치
	cin >> n >> k;

	for (int i = 0; i < n; i++) { //동전의 가치 오름차순으로 입력 
		int a;
		cin >> a;
		value.push_back(a);
	}
	
	//가장 큰 화폐단위부터 나누면 최솟값을 구할 수 있다.
	//가장 큰 화폐단위부터 나누기위해 내림차순 정렬
	sort(value.rbegin(), value.rend()); //reverse sort

	for (int i = 0; i < n; i++) { 
		while (k - value[i] >= 0) { //입력된 k보다 작은 수의 화폐단위 갯수만큼 반복문 실행
			k-=value[i];
			min++;
		}
	}
	cout << min << endl;
}