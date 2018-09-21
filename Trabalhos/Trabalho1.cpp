#include <iostream>
using namespace std;

class Matriz{
	private:
		int L, C, **Matriz1;

	public:
		Matriz();
		int GetL();
		int GetC();
		void ValLC();
		void MatrizAssigner();
		void MosVal();
};
void Matriz::ValLC(){
	cout<<"Digite o número de linhas da matriz:"<<endl;
	cin>>L;
	this->L=L;
	cout<<"Digite o numero de colunas da matriz:"<<endl;
	cin>>C;
	this->C=C;
}
int Matriz::GetL(){
	return L;
}
int Matriz::GetC(){
	return C;
}
Matriz::Matriz(){
	int i;
	int L1=GetL();
	int C1=GetC();
	int **Mat;
	Mat= new int*[L1];
	for(i=0;i<L1;i++){
		Mat[i]= new int[C1];
	}
	Matriz1=Mat;
}
void Matriz::MatrizAssigner(){
	int i,j;
	int L1=GetL();
	int C1=GetC();
	for(i=0;i<L1;i++){
		for(j=0;j<C1;j++){
		Matriz1[i][j]=(i+1)*10+j+1;
		}
	}
}

void Matriz::MosVal(){
	int i,j;
	int L1=GetL();
	int C1=GetC();
	for(i=0;i<L1;i++){
		cout<<endl;
		cout<<"|";
        for(j=0;j<C1;j++){
			cout<<" A"<<Matriz1[i][j];
		}
		cout<<"|";
	}
}
void DarValor(Matriz *Mat){
	Mat->ValLC();
	Mat->MatrizAssigner();
	Mat->MosVal();
}
int main(){
	Matriz Mat;
 	DarValor(&Mat);
    return 0;
}
