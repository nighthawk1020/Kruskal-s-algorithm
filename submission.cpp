#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
struct Edge{
	int node1;
	int node2;
	int weight;
	Edge(int a, int b, int c){
		node1 = a;
		node2 = b;
		weight = c;
	}
	static bool mySort(const Edge& lhs, const Edge& rhs){
		return lhs.weight > rhs.weight;
	}
};
int main(){
	Edge s1(1, 2, 80);
	Edge s2(5, 9, 73);
	Edge s3(9, 13, 69);
	Edge s4(2, 3, 10);
	Edge s5(5, 7, 20);
	Edge s6(5, 2, 74);
	Edge s7(9, 18, 15);
	Edge s8(13, 14, 21);
	Edge s9(9, 1, 92);
	Edge s10(13, 2, 59);
	Edge s11(20, 4, 6);
	Edge s12(18, 17, 17);
	Edge s13(7, 18, 83);
	Edge s14(7, 12, 27);
	Edge s15(1, 10, 16);
	Edge s16(5, 15, 47);
	Edge s17(20, 14, 94);
	Edge s18(14, 18, 77);
	Edge s19(2, 4, 30);
	Edge s20(11, 14, 62);
	Edge s21(3, 20, 85);
	Edge s22(11, 7, 62);
	Edge s23(6, 10, 87);
	Edge s24(12, 15, 81);
	Edge s25(3, 19, 39);
	Edge s26(9, 8, 45);
	Edge s27(19, 4, 65);
	Edge s28(8, 16, 70);
	Edge s29(15, 17, 64);
	Edge s30(1, 11, 32);
	Edge s31(11, 6, 43);
	Edge s32(12, 6, 87);
	Edge s33(12, 19, 70);
	Edge s34(7, 16, 39);
	Edge s35(13, 6, 22);
	Edge s36(4, 16, 68);
	Edge s37(17, 10, 56);
	Edge s38(19, 15, 71);
	Edge s39(11, 3, 74);
	Edge edgeArr[39]= {s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16,s17,s18,s19,s20,s21,s22,s23,s24,s25,s26,s27,s28,s29,s30,s31,s32,s33,s34,s35,s36,s37,s38,s39};
	int sets[21];
	for(int i = 0; i < 21; i++){
		sets[i] = i;
	}
	bool visited[21];
	for(int i = 0; i < 21; i++){
		visited[i] = false;
	}sort(edgeArr, edgeArr+40, Edge::mySort);
	int numVertices = 20;
	int numEdges = 0;
	int index = 0;
	int setCount = 0;
	while(numEdges < numVertices - 3){
		if(!visited[edgeArr[index].node1] && !visited[edgeArr[index].node2]){
			sets[edgeArr[index].node2] = sets[edgeArr[index].node1];
			setCount++;
			numEdges++;
			visited[edgeArr[index].node1] = true;
			visited[edgeArr[index].node2] = true;
		}else if(visited[edgeArr[index].node1] && visited[edgeArr[index].node2]){
			if(sets[edgeArr[index].node1] != sets[edgeArr[index].node2]){
				if(setCount >= 3){
					numEdges++;
					setCount--;
					int tempNum = sets[edgeArr[index].node2];
					for(int i = 0; i < 21; i++){
						if(sets[i] == tempNum){
							sets[i] = sets[edgeArr[index].node1];
						}
					}
				}
			}
		}else{
			numEdges++;
			if(visited[edgeArr[index].node1]){
				sets[edgeArr[index].node2] = sets[edgeArr[index].node1];
				visited[edgeArr[index].node2] = true;
			}else{
				sets[edgeArr[index].node1] = sets[edgeArr[index].node2];
				visited[edgeArr[index].node1] = true;
			}
		}index++;
	}int count = 0;
	string temp = "";
	for(int i = 1; i < 21; i++){
		if(sets[i] != 1000){
			cout<<"number of pictures for this set is ";
			int tempNum = sets[i];
			for(int j = 1; j < 21; j++){
				if(sets[j] == tempNum){
					count++;
					temp += to_string(j) + " ";;
					sets[j] = 1000;
				}
			}cout<<count<<endl;
			count = 0;
			cout<<"The pictures in this set are: "<<temp<<endl;
			temp = "";
		}
	}return 0;
}
