
int asc_compare(int a, int b) {
    if (a > b)
        return 1;
    else
        return 0;
}

int abs_compare(int a, int b) {
    if (abs(a) > abs(b)
        return 1;
    else
        return 0;
}


void sort (int *a, int n, int compare) {

	int i, j;
	
	for (i = 0; i<n; i++) {
		for (j=0; j<n-1; j++) {
			if (compare(a[i], a[i+1]) > 0) { /* ascneding */
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
			}
		}
	}
}



void main  ()

{
    int a[45, 67, -1, 3]

    int (*mysort) (int, int);
    
    mysort  = asc_compare();
    
    sort(a, 4, asc_compare);
    
}