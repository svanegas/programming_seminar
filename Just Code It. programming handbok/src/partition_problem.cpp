vector <int> arr;

/* part[i][j] = true if a subset of {arr[0], arr[1], ..arr[j-1]}
                has sum equal to i, otherwise false */
bool findPartiion (int n) {
  int sum = 0;
  int i, j;
  for (i = 0; i < n; i++) sum += arr[i];
  if (sum % 2 != 0) return false;
  
  bool part[sum / 2 + 1][n + 1];
  // Initialize top row as true
  for (i = 0; i <= n; i++) part[0][i] = true;
  // Initialize leftmost column, except part[0][0], as 0
  for (i = 1; i <= sum / 2; i++) part[i][0] = false;     
    // Fill the partition table in botton up manner 
    for (i = 1; i <= sum/2; i++) {
      for (j = 1; j <= n; j++) {
        part[i][j] = part[i][j-1];
        if (i >= arr[j-1])
          part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
      }        
    }    
  /* Uncomment this part to print table.
   for (i = 0; i <= sum/2; i++)  
   {
     for (j = 0; j <= n; j++)  
        printf ("%4d", part[i][j]);
     printf("\n");
   } */
  return part[sum/2][n];
}     
