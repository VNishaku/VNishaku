#include<iostream>
using namespace std;
//2. can i place a queen here or not //
bool isSafe(int**arr, int x, int y, int n){
	//3. two dimensional array, xaxis, yaxis, n number of queens//
	//4. first i wanna check for each row //
	for(int row=0;row<x;row++){
		if(arr[row][y]==1){
			//5. if the queen is in these rows then return false //
			return false;
		}
	}
	//6. now i want to check diagonaly in each row //
	int row=x;
	int col=y;
	//7. i dont know how many rows and its diagonal exists //
	while(row>=0 && col>=0){
		//8. checking in left diagonal //
		if(arr[row][col]==1){
			return false;
		}
		row--;
		col--;
	}
	//9. checking again but towards right //
	row=x;
	col=y;
	while(row>=0 && col<n){
		//10. because i dont know the length of columns //
		if(arr[row][col]==1){
			return false;
		}
		row--;
		col++;
	}
	return true;
}
//11. function for nQueen //
bool nQueen(int**arr, int x, int n){
	//12. now we putted a queen at a place //
	if(x>=n){
		return true;
	}
	//13. now checking in columns //
	for(int col=0;col<n;col++){
		if(isSafe(arr,x,col,n)){
			//14. place exist to put a queen //
			arr[x][col]==1;
			if(nQueen(arr,x+1,n)){
				//15. again line 14 //
				return true;
			}
			arr[x][col]==0;
			//16. backtracking //
		}
	}
	return false;
}
//0. In main fuction we call other functions and define parementers and get input from a user //
int main(){
	// 1.i wanna get input from user //
	int n;
	cin>>n;
	//17. define two dimensional array //
	int**arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int [n];
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	//18. sorry i forget to call you //
	if(nQueen(arr,0,n)){
		//19. printing //
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}cout<<endl;
		}
	}
	return 0;	
}