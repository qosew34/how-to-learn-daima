#include <bits/stdc++.h>
using namespace std;

int main(){
    string phone;
    cin >> phone;
    
    // Extract unique digits and sort in descending order
    set<int> uniqueDigits;
    for(char c : phone){
        uniqueDigits.insert(c - '0');
    }
    
    // Convert set to vector and sort in descending order
    vector<int> arr(uniqueDigits.begin(), uniqueDigits.end());
    sort(arr.begin(), arr.end(), greater<int>());
    
    // Create index array
    vector<int> index;
    for(char c : phone){
        int digit = c - '0';
        // Find position of digit in arr
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == digit){
                index.push_back(i);
                break;
            }
        }
    }
    
    // Output arr
    cout << "int[] arr = new int[]{";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i];
        if(i < arr.size() - 1) cout << ",";
    }
    cout << "};" << endl;
    
    // Output index
    cout << "int[] index = new int[]{";
    for(int i = 0; i < index.size(); i++){
        cout << index[i];
        if(i < index.size() - 1) cout << ",";
    }
    cout << "};" << endl;
    
    return 0;
}
