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
    
    int count=0;
    int index[100];
    j=0;
    
    for(i=0;i<1024;i++){
      if(arr[i]==1&&arr[i+1]==1&&arr[i+2]==0&&arr[i+3]==1&&arr[i+4]==0&&arr[i+5]==1&&arr[i+6]==1&&arr[i+7]==0&&arr[i+8]==0&&arr[i+9]==0&&arr[i+10]==0&&arr[i+11]==0&&arr[i+12]==1&&arr[i+13]==0&&arr[i+14]==1&&arr[i+15]==1){
        count++;
        index[j++]=i;
        i=i+15;
      }  
    }
    
    cout<<"the no of time it got correlated with 1101011000001011 are "<<count<<endl;
    cout<<"the indexes at which it got correlated are"<<endl;
    
    for(i=0;i<count;i++)
    cout<<index[i]<<" ";
    
return 0;

}
