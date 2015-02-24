#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
struct Team
{
	string name;
	int point;
	int shoot;
	int deduc;
	int sum;
	Team(string n)
    :name(n),point(0),shoot(0),deduc(0)
    {}
};
Team* set[4];
int board[4][4];
bool acompare(Team* lhs, Team* rhs){ 
	if(lhs->point == rhs->point){
		if(lhs->sum == rhs->sum){
			return lhs-> shoot > rhs->shoot;
		}
		return lhs->sum > rhs->sum;
	}
	return lhs->point > rhs->point;
}
int main(){
	for(int i =0 ;i<4;i++){
		string tmp;
		cin >> tmp;
		set[i] = new Team(tmp);
	}

	for (int i = 0; i < 4; i++)
	{
		for(int j=0;j<4;j++){
			scanf("%d",&board[i][j]);
		}
	}

	for(int i =0;i<4;i++){
		for (int j = i+1; j < 4; j++)
		{	
			int ca = board[i][j];
			int cb = board[j][i];
			if(ca>cb)(set[i]->point)+=3;
			else if(cb>ca)(set[j]->point)+=3;
			else{
				(set[i]->point)+=1;
				(set[j]->point)+=1;
			}
			(set[i]->shoot)+=ca;
			(set[j]->shoot)+=cb;
			(set[i]->deduc)+=cb;
			(set[j]->deduc)+=ca;
			(set[i]->sum) = (set[i]->shoot)-(set[i]->deduc);
			(set[j]->sum) = (set[j]->shoot)-(set[j]->deduc);

		}
	}
	sort(set, set+4, acompare);

	for (int i = 0; i <4; ++i)
	{
		printf("%s %d\n",(set[i]->name).c_str(),set[i]->point);
	}
	return 0;
}