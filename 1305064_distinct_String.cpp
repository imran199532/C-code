#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Structure to store information of a suffix
struct suffix
{
    int id; // To store original id
    int rank[2]; // To store ranks and next rank pair
    bool operator<(const suffix& b)const{
        return (rank[0] == b.rank[0])? (rank[1] < b.rank[1] ?1: 0):
               (rank[0] < b.rank[0] ?1: 0);
    }
};

int suffixArr[100000],lcp[10000],n;

// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller


// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
void fun(string txt, int n)
{
    // A structure to store suffixArray and their indexes
    struct suffix suffixArray[n];

    // Store suffixArray and their indexes in an array of structures.
    // The structure is needed to sort the suffixArray alphabatically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++)
    {
        suffixArray[i].id = i;
        suffixArray[i].rank[0] = txt[i] - 'a';
        suffixArray[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }

    // Sort the suffixArray using the comparison function
    // defined above.
    sort(suffixArray, suffixArray+n);

    int ind[n];  // This array is needed to get the id in suffixArray[]
                 // from original id.  This mapping is needed to get
                 // next suffix.
    for (int k = 4; k < 2*n; k = k*2)
    {
        // Assigning rank and id values to first suffix
        int rank = 0;
        int prev_rank = suffixArray[0].rank[0];
        suffixArray[0].rank[0] = rank;
        ind[suffixArray[0].id] = 0;

        // Assigning rank to suffixArray
        for (int i = 1; i < n; i++)
        {
            // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
            if (suffixArray[i].rank[0] == prev_rank &&
                    suffixArray[i].rank[1] == suffixArray[i-1].rank[1])
            {
                prev_rank = suffixArray[i].rank[0];
                suffixArray[i].rank[0] = rank;
            }
            else // Otherwise increment rank and assign
            {
                prev_rank = suffixArray[i].rank[0];
                suffixArray[i].rank[0] = ++rank;
            }
            ind[suffixArray[i].id] = i;
        }

        // Assign next rank to every suffix
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixArray[i].id + k/2;
            suffixArray[i].rank[1] = (nextindex < n)?
                                  suffixArray[ind[nextindex]].rank[0]: -1;
        }

        // Sort the suffixArray according to first k characters
        sort(suffixArray, suffixArray+n);
    }

    // Store indexes of all sorted suffixArray in the suffix array

    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixArray[i].id;

    // Return the suffix array
    return ;
}


int buildLcp(string txt)
{
    int inv[n];
    for(int i=0;i<n;i++)inv[i]=0;

    for(int i=0;i<n;i++)inv[suffixArr[i]]=i;

    int len=0;
    for(int i=0;i<n;i++)
    {
        if(inv[i]==n-1){
            len=0;
            continue;
        }

        int k=suffixArr[inv[i]+1];

        while(i+len<n && k+len<n){
            if(txt[i+len]!=txt[k+len])break;
            len++;

        }

        lcp[inv[i]]=len;
        if(len>0)len--;



    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=n-lcp[i]-suffixArr[i];
    }
    return ans;

}


int main()
{
    string input;
    cin>>input;
    n=input.size();

    fun(input,  n);


    int ans=buildLcp(input);

    for(int i=0;i<n;i++)cout<<lcp[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;



    return 0;
}
