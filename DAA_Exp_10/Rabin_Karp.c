#include <stdio.h>
#include <string.h>

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int p = 0, t = 0, h = 1, d = 256; 
	int i, j;

	for (i = 0; i < M - 1; i++) {
		h = (h * d) % q;
    }

	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (i = 0; i <= N - M; i++) {
		if (p == t) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
                }
			}
			if (j == M) {
				printf("\nPattern found at index %d \n", i);
            }
		}

		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			if (t < 0) {
				t = (t + q);
            }
		}
	}
}

int main()
{
	char txt[100], pat[100];
    printf("\nEnter the text: ");
    scanf("%[^\n]s",txt);
    getchar();
    printf("\nEnter the pattern: ");
    scanf("%[^\n]s",pat);
	int q = 101;
	search(pat, txt, q);
	return 0;
}
