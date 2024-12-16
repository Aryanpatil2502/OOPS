#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
		typedef map<string , int>mapType;
		mapType populationMap;
		
		    populationMap.insert(pair<string,int>("Maharashtra",1234));
			populationMap.insert(pair<string,int>("Goa",1334));
			populationMap.insert(pair<string,int>("Madhya Pradesh",1524));
			populationMap.insert(pair<string,int>("Rajasthan",1634));
			populationMap.insert(pair<string,int>("Kerla",1111));
			populationMap.insert(pair<string,int>("Karnataka",134));
   	 		populationMap.insert(pair<string,int>("Assam",12));

mapType::iterator iter;
cout<<"Size of the population map : "<<populationMap.size()<<'\n';
for (iter = populationMap.begin();iter !=populationMap.end();++iter){
		cout<<iter->first<<" : "<<iter->second <<"million \n";
		}
	string state,ch;
	do
	{
	
	cout<<"Enter state name to check population : ";
	cin>>state ;
	iter = populationMap.find(state);
	if(iter !=populationMap.end()){
		cout<<state<<"'s population is "<<iter->second<<"million \n";}
	else
	{cout<<"Key is not in population map "<<"\n";}
	
	cout<<"Do you wish to continue?(y/n):";
		cin>>ch;
}while(ch== "y" || ch=="Y");
	populationMap.clear();
	
	}
