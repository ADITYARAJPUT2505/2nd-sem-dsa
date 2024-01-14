#include<iostream>
using namespace std;

void bubblesort(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int comp = 0, swap = 0, temp;
    
    for (int i = 0; i < n-1; i++) {
        for (int j =0 ; j < n -1-i; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    cout << "Number of comparisons and swaps: " << comp << " " << swap;
}
void selectionsort(int n, int arr[])
{
	for(int i=0 ; i< n ; i++)
	{
		cin>>arr[i];
	}
	int comp=0 ,  swap=0 , temp ,min_index;
	for(int i=0 ; i<n-1 ; i++)
	{   
	    min_index=i;
		for(int j=i+1 ; j<n ; j++)
		{
			++comp;
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
			if(min_index!=i)
			{
				++swap;
			    temp=arr[i];
				arr[i]=arr[min_index];
				arr[min_index]=temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    cout << "Number of comparisons and swaps: " << comp << " " << swap;
}
void insertionsort(int n , int arr[])
{
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}
	int comp=0 , swap=0 ,key,j;
	for(int i=1 ; i<n ; i++)
	{   
	    comp++;
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]<key)
		{   
		    swap++;
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    cout << "Number of comparisons and swaps: " << comp << " " << swap;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    printf("Enter the elements of the array: ");
    bubblesort(n, arr);
    selectionsort(n , arr);
    insertionsort(n , arr);
    
    return 0;
}

