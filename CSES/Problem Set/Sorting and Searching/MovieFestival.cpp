#include<bits/stdc++.h>	
using namespace std;

struct movie {
	int start;
	int end;

};

bool sortMovies(movie a, movie b)
{
	return a.end < b.end;
}

int main()
{
	int n; cin >> n;

	vector<movie> movies;
	for (int i = 0; i < n; i++)
	{
		movie temp;
		cin >> temp.start >> temp.end;
		movies.push_back(temp);
	}

	sort(movies.begin(), movies.end(), sortMovies);

	int moviesWatched = 0;
	int lastWatched = 0;
	for (int i = 0; i < n; i++)
	{
		if (movies[i].start >= lastWatched)
		{
			moviesWatched++;
			lastWatched = movies[i].end;
		}
	}

	cout << moviesWatched;
}