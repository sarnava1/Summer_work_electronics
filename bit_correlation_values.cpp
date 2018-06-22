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

    
    cout<<endl;
    string s;
    int slength;
    cout<<"enter the length of the sequence with which you want to correlate the prbs sequence"<<endl;
    cin>>slength;
    cout<<"enter the sequence with which you want to correlate the PBRS-9 sequence : "<<endl;
    cin>>s;
	   
    int count=0;
    int index[1000];
    j=0;

    int k=0;
    int matchcount=0;
    j=0;
    float sum=0.0;
    int cindex[1024];
    for(i=0;i<=1024-slength;i++){
    	k=0,matchcount=0;
    	while(arr[i+k]==s[k]-'0'&&k<slength){
     		k=k+1;
    	    matchcount=matchcount+1;	
		}
		if(matchcount==slength){
			count++;
		    index[j++]=i;	
		}
		
	}
    cout<<endl;

    cout<<"the no of time it got correlated with "<<s<<" are "<<count<<endl;
    cout<<endl;
    
    cout<<"the indexes[0th index] at which it got correlated are"<<endl;
    cout<<endl;
    
    for(i=0;i<count;i++)
    cout<<index[i]<<" ";
    
    cout<<endl;
    cout<<endl;
    
    //1024-slength
    
    int n=0,m,p=0;
    int cslength=slength-1;
    int innerlooplength=cslength;
    m=0;
    while(cslength>=1){
    	sum=0;n=0;
    	for(p=m;p>=0;p--){
    		//sum=0;
    		//cout<<"p "<<p<<"n "<<n<<"m "<<m<<endl;
    		if((s[innerlooplength-n++]-'0')==arr[p]){
    			sum=sum+1;
    			//cout<<"sum "<<sum<<"p "<<p<<"n "<<n<<endl;
			}
		}
		float ans=sum/slength;
		if(ans==1.0)
		cout<<fixed<<setprecision(1)<<ans<<" peak found     ";
		else
		cout<<fixed<<setprecision(1)<<ans<<"     ";
		m++;
      	cslength--;
	}



	for(i=0;i<=1024-slength;i++){
    	k=0;sum=0.0;
		while(k<slength){
			if(arr[i+k]==(s[k]-'0')){
			   sum++;	
			}
			
			k++;
		}
		float ans=sum/slength;
		if(ans==1.0)
		cout<<fixed<<setprecision(1)<<ans<<" peak found     ";
		else
		cout<<fixed<<setprecision(1)<<ans<<"     ";
		//cout<<endl;
	}
    
    //cout<<"s length"<<slength<<"m "<<m<<endl;
    m=slength-1;
    cslength=slength-1;
    n=0;
    //cout<<endl;
    while(cslength>=1){
    	sum=0;
    	for(p=0;p<m;p++){
    		if(arr[1024-slength+1+p+n]==(s[p]-'0')){
    			sum=sum+1;
    			//cout<<"sum "<<sum<<"p "<<p<<"m "<<m<<endl;
			}
		}		
		//cout<<"p "<<p<<" sum "<<sum<<" m "<<m<<endl;
		cout<<fixed<<setprecision(1)<<sum/slength<<"     ";
		m--;
		n++;
      	cslength--;
	}




return 0;

}
