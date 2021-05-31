// https://www.spoj.com/problems/GCJ101BB/
// if there are chicks which can't reach the barn infront og chicks who can then they will act as 
// obstruction and wont allow the chick which can reach the barn 

int swap = 0;
int N, K;
LL B,T;
cin >> N >> K >> B >> T;
for (int i = 1; i <= N; i++)
	cin >> startPT[i];

for (int i = 1; i <= N; i++)
	cin >> speed[i];

int count = 0;
int cantReach = 0;


// going from end as we dont have to bring chicks from the last if there are enough towards the end
// as it will cost less number of swaps
for (int i = N; i >= 1; i--)
{
	LL distance = B - startPT[i];
	//LL time = distance / speed[i];   // this was a mistake time was gettig rounded off

	LL canCover = T*speed[i];

	if (distance <= canCover)        // the chick can reach the barn
	{
		count++;

		if (cantReach > 0)   // has some obstruction in-front of it
		{
			swap += cantReach;
			//cantReach = 0; dont reset it swap has to be done for all
		}
	}

	else   //can't reach the barn
		cantReach++;

	if (count == K)
		break;
}

	if (count < K)
	{
		cout << "Case #" << t++ << ": " << "IMPOSSIBLE" << endl;
	}
	else
	{
		cout << "Case #" << t++ << ": " << swap << endl;
	}
