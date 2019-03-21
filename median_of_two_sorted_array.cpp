#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();

    double median = 0;
    if(m==0){
        if(n%2==0){
            median = ((double)B[n/2] + (double)B[n/2-1])/2.0;
        }
        else median = B[n/2];
        return median;
    }
    if(n==0){
        if(m%2==0){
            median = ((double)A[m/2] + (double)A[m/2-1])/2.0;
        }
        else median = A[m/2];
        return median;
    }

    int al=0,ar=m-1,bl=0,br=n-1;
    int amid, bmid;
    amid = (m-1)/2;
    bmid = (n-1)/2;
    while(amid>=0 && bmid>=0 && al<=ar && bl<=br){
  
        if(A[amid]>B[bmid]){
            if(bmid == n-1) break;
            else if(A[amid]>B[bmid+1]){
                int tmp = bmid;

                bl = bmid+1;
                br = bmid + min(br-bmid, amid);
                if(bl>br){ 
                	if(amid==0) amid--;
                	break;
                }	
                ar = amid - 1;
                al = ar - (br-bl);
                bmid = (bl+br)/2;
                amid -= (bmid-tmp);
            }
            else break;
        }
        else if(A[amid]<B[bmid]){
            if(amid == m-1) break;
            else if(B[bmid]>A[amid+1]){
                int tmp = amid;

                al = amid+1;
                ar = amid + min(ar-amid, bmid);
                if(al>ar){ 
                	if(bmid==0) bmid--;
                	break;
                }
                br = bmid - 1;
                bl = br - (ar-al);
                amid = (al+ar)/2;
                bmid -= (amid-tmp);
            }
            else break;
        }
        else break;
    }
    
    if((m+n)%2==0){
        if(amid<0){
            median = (min(B[(m+n)/2],A[0]) + B[(m+n)/2 - 1])/2.0;
            return median;
        }
        if(bmid<0){
            median = (min(A[(m+n)/2],B[0])+ A[(m+n)/2 - 1])/2.0;
            return median;
        }
        
        if(m%2==0 && n%2==0){
            median = max(A[amid], B[bmid]);
            if(amid == m-1){
                median = (median + B[bmid+1])/2.0;
            }
            else if(bmid == n-1){
                median = (median + A[amid+1])/2.0;
            }
            else{
                median = (median + min(A[amid+1],B[bmid+1]))/2.0;
            }
            return median;    
        }

        if(A[amid]>B[bmid]){
            if(amid>0){
                if(B[bmid]<A[amid-1]) return (A[amid]+A[amid-1])/2.0;
            }
        }
        else if(A[amid]<B[bmid]){
            if(bmid>0){
                if(B[bmid-1]>A[amid]) return (B[bmid]+B[bmid-1])/2.0;
            }
        }

        return (A[amid] + B[bmid])/2.0;
    }
    else {
        if(amid<0) return B[(m+n)/2];
        if(bmid<0) return A[(m+n)/2];
        return max(A[amid], B[bmid]);
    }
}

int main() {
	vector<int> A{-50, -47, -36, -35, 0, 13, 14, 16};
	vector<int> B{-31, 1, 9, 23, 30, 39 };
//	vector<int> A{1,4,5, 11, 15, 19};
//	vector<int> B{8,9};
	cout<<findMedianSortedArrays(A, B);
	return 0;
}