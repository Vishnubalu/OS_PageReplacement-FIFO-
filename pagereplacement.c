#include<stdio.h>
int pagereplacement(int k, int pages[],int n)
{
      int frame[k];
      for(int i=0; i<k; i++)
      {
        frame[i] = -1;
      }
    int faults=0, hit=0;
    int len_frame =  k; //sizeof(frame)/sizeof(int);
    int len = len_frame;

    for(int i=0; i<n; i++)
    {
        int count = 0;
        for(int j=0; j<len_frame; j++)
        {
            if(pages[i] == frame[j])
            {
                count++;
            }
        }
        if(count != 0)
        {
            hit++;
        }
        else
          {
            if(len >= len_frame)
              {
                len = 0;
              }
              frame[len] = pages[i];
              len++;
              faults++;
          }
    }
    printf("no. of frames : %d      | faults : %d    hits   : %d\n", k, faults, hit);
//}
}
int main()
{
  int pages[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
  for(int k=1; k<8; k++)
  {
    pagereplacement(k, pages, sizeof(pages)/sizeof(int));
  }

}
