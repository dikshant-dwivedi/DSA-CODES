#include <iostream>
#include <vector>
using namespace std;

/*int bestSum(int A[], int n)
{
    int best_sum = -32767;
    int curr_sum = 0;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = max(A[i], curr_sum + A[i]);
        if(curr_sum < 0)
        {
            start = end = i + 1;
        }
        else
            end = i + 1;
        
        best_sum = max(curr_sum, best_sum);

        cout << "iteration: " << i << endl;
        cout << "curr_sum: " << curr_sum << "\tbest_sum: " << best_sum << endl;

        for(int j = start; j <= end; j++)
            cout << A[j] << " ";
        cout << "\n------------------------------\n";
    }

    return best_sum;
}

int main()
{
    int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "max sum = " << bestSum(A, 9);
    return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

void maxset(vector<int> &A)
{
    float curr_sum = 0, best_sum = -32767;
    int temp_start = 0, temp_end = -1;
    int final_start = 0, final_end = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] >= 0)
        {
            curr_sum += A[i];
            temp_end += 1;
        }
        else
        {
            curr_sum = 0;
            temp_start = i + 1;
            temp_end = i;
        }

        if (curr_sum > best_sum || (curr_sum == best_sum && (final_end - final_start < temp_end - temp_start)))
        {
            final_start = temp_start;
            final_end = temp_end;
            best_sum = curr_sum;
        }
    }

    cout << "final start: " << final_start << " final end: " << final_end << endl;
    for (int i = final_start; i <= final_end; i++)
        cout << A[i] << " ";
}

int main()
{
    //int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> A;
    /*A.push_back(1);
    A.push_back(2);
    A.push_back(5);
    A.push_back(-7);
    A.push_back(3);
    A.push_back(2);
    A.push_back(2);
    A.push_back(30);
    A.push_back(2);
    A.push_back(0);
    A.push_back(0);
    A.push_back(-1);
    A.push_back(0);*/
    A.push_back(1967513926);
    A.push_back(1540383426);
    A.push_back(-1303455736);
    A.push_back(-521595368);
    maxset(A);
    return 0;
}