#include <iostream>
#include <vector>

using namespace std;

struct Counter
{
    int zeroco = 0;
    int oneco = 0;
};

vector<Counter> v(41);


// Precompute all Fibonacci call counts from 0 to 40
void fill_fibonacci_table() {

		// Base cases
    v[0].zeroco = 1; v[0].oneco = 0;
    v[1].zeroco = 0; v[1].oneco = 1;

		// Fill the table using bottom-up dynamic programming
    for (int i = 2; i <= 40; i++) {
        v[i].zeroco = v[i - 1].zeroco + v[i - 2].zeroco;
        v[i].oneco = v[i - 1].oneco + v[i - 2].oneco;
    }
}

int main() {

    // Improve I/O performance by disabling synchronization with C I/O
    ios_base::sync_with_stdio(false);
    // Untie cin from cout to allow independent flushing
    cin.tie(NULL);


		// call fill_fibonacci function
    fill_fibonacci_table();


    vector<int> number;
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int n = 0;
        cin >> n;
        number.push_back(n);
    }

    for (auto n : number) {
        cout << v[n].zeroco << " " << v[n].oneco << <"\n";  // change endl; to \n
    }


    return 0;
}
