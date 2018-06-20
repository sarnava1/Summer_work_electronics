#include<bits/stdc++.h>
#include<stdint.h>

using namespace std;

int main() {
	// your code goes here
	uint16_t start = 0xA0; 
    uint16_t j, reg, a = start;
    int arr[1024];
    int i;
    for(i=0;i<200;i++){
        arr[i]=rand()%2;
    }
    
    arr[200]=(start&0x0001);
    
    for(j = 201; ; j++) {

        reg = ((a) ^ (a >> 4)) & 1;
        a = ((a >> 1) | reg << (8));

        

        arr[j]=(reg&0x0001);


        /* Stop condition */
        if (a == start) {
            break;
            //break;
        }
	
    }
    
    for(j=711;j<1024;j++)
    arr[j]=rand()%2;
    
    for(i=0;i<1024;i++)
    cout<<arr[i]<<" ";
    
    cout<<endl;
    string s;
    cout<<"enter the string with which you want to correlate the PBRS-9 sequence : "<<endl;
    cin>>s;
	   
    int count=0;
    int index[100];
    j=0;
    
    for(i=0;i<1009;i++){
      if(arr[i]==s[0]-'0'&&arr[i+1]==s[1]-'0'&&arr[i+2]==s[2]-'0'&&arr[i+3]==s[3]-'0'&&arr[i+4]==s[4]-'0'&&arr[i+5]==s[5]-'0'&&arr[i+6]==s[6]-'0'&&arr[i+7]==s[7]-'0'&&arr[i+8]==s[8]-'0'&&arr[i+9]==s[9]-'0'&&arr[i+10]==s[10]-'0'&&arr[i+11]==s[11]-'0'&&arr[i+12]==s[12]-'0'&&arr[i+13]==s[13]-'0'&&arr[i+14]==s[14]-'0'&&arr[i+15]==s[15]-'0'){
        count++;
        index[j++]=i;
        i=i+15;
      }  
    }
    
    cout<<"the no of time it got correlated with "<<s[i]<<" are "<<count<<endl;
    cout<<"the indexes at which it got correlated are"<<endl;
    
    for(i=0;i<count;i++)
    cout<<index[i]<<" ";
    
return 0;

}
