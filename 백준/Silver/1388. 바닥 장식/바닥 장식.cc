#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;
// 첫째 줄에 방 바닥의 세로 크기N과 가로 크기 M이 주어진다.
// 둘째 줄부터 N개의 줄에 M개의 문자가 주어진다. 이것은 바닥 장식 모양이고, '-‘와 ’|‘로만 이루어져 있다.
// N과 M은 50 이하인 자연수이다.

int n, m;
char graph[50][50];
char tmp[50][50];
int graph2[50][50];

//dfs함수 정의 ('-'의 경우)
bool dfs_h(int x, int y) {
	//주어진 범위를 벗어나는 경우 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	//현재노드를 아직 방문하지 않았다면
	if (graph2[x][y] == 0) {
		//해당 노드 방문처리
		graph2[x][y] = 1;
		//상,하 위치 재귀적으로 호출
		dfs_h(x, y + 1); //우
		dfs_h(x, y - 1); //좌
		return true;
	}
	return false;
}

bool dfs_v(int x, int y) { // '|'의 경우
	//주어진 범위를 벗어나는 경우 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	//현재노드를 아직 방문하지 않았다면
	if (graph2[x][y] == 0) {
		//해당 노드 방문처리
		graph2[x][y] = 1;
		//좌,우 위치 재귀적으로 호출
		dfs_v(x + 1, y); //하
		dfs_v(x - 1, y); //상
		return true;
	}
	return false;
}

// '-'과 '|' 가 입력되면 각각 0과 1로 변환하기
// 특정한 지점의 상,하,좌,우를 살펴본 뒤 주변 지점 중 값이 '0'이면서 아직 방문하지 않은 지점이 있다면 해당 지점 방문
// 아직 방문하지 않은 지점이 있다면 해당 지점 방문
// '|'인 경우도 반복하여 count

int main(void) { 
	cin >> n >> m;
	int horizontal = 0;
	int vertical = 0;

	for (int i = 0; i < n; i++) { //2차원 리스트에 정보 입력받기
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			tmp[i][j] = graph[i][j]; //스위치할때 쓰일 임시 값 저장
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == '-') {
				graph2[i][j] = 0;
			}
			else if (graph[i][j] == '|') {
				graph2[i][j] = 1;
			}
		}
	}

	//dfs로 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs_h(i, j)) {
				horizontal += 1;
			}
		}
	}
	
	// dfs함수는 0인 값을 탐색하므로 이번엔 '-'과 '|' 설정값을 바꿔서 다시 dfs함수 실행
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == '-') {
				graph2[i][j] = 1;
			}
			else if (tmp[i][j] == '|') {
				graph2[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs_v(i, j)) {
				vertical += 1;
			}
		}
	}

	cout << horizontal+vertical;
}
