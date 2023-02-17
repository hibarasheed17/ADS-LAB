#include <stdio.h>
#include <ctype.h>
#define max_size 26

int set1[max_size], set2[max_size], result[max_size];
char ele1[max_size], ele2[max_size];
char alpahbets[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 

void initializeSets()
{
    int i;
    for (i=0;i<max_size;i++)
    {
        set1[i] = 0;
        set2[i] = 0;
        result[i] = 0;
    }
}
int findIndex(char val)
{
    int i;
    for(i=0;i<max_size;i++)
    {
        if(alpahbets[i] == val)
            return(i);
    }
}
void makeSet(char ary[max_size], int setary[max_size])
{
    int i=0, indx;
    while(ary[i] != '\n')
    {
        if (ary[i] != ' ')
        {
            indx = findIndex(toupper(ary[i]));
            setary[indx] = 1;
        }
        i = i + 1;
    }
}
void setUnion(int set1[max_size], int set2[max_size])
{
    int i;
    for(i=0;i<max_size;i++)
    {
        result[i] = set1[i] | set2[i];
    }
}
void setIntersection(int set1[max_size], int set2[max_size])
{
    int i;
    for(i=0;i<max_size;i++)
    {
        result[i] = set1[i] & set2[i];
    }
}
void setComplement(int set1[max_size])
{
    int i;
    for(i=0;i<max_size;i++)
    {
        if(set1[i] == 0)
            result[i] = 1;
        else
            result[i] = 0;
    }
}
void setDifference(int set1[max_size], int set2[max_size])
{
    setComplement(set2);
    setIntersection(set1, result);
}
void printBitSet(int ary[max_size])
{
    int i=0;
    for(i=0;i<max_size;i++)
        printf("%d",ary[i]);
}
void printSet(int ary[max_size])
{
    int i, flag=0;
    printf("{");
    for(i=0; i<max_size; i++)
    {
        if(ary[i] == 1)
        {
            if(flag != 0)
            {
                printf(" %c", alpahbets[i]);
            }
            else
            {
                flag=1;
                printf("%c", alpahbets[i]);
            }
        }
    }
    printf("}");
}
void main()
{
    printf(" Set operation with Bit Vector Representation \n");
    printf(" -------------------------------------------- \n");
    initializeSets();
    printf("Enter the elements of the first set (separate with space): ");
    fgets(ele1, sizeof(ele1), stdin);
    printf("Enter the elements of the second set (separate with space): ");
    fgets(ele2, sizeof(ele2), stdin);
    makeSet(ele1, set1);
    makeSet(ele2, set2);
    setUnion(set1, set2);
    printf("Set Union (Set1 U Set2):");
    printBitSet(result);
    printf(" - ");
    printSet(result);
    printf("\n");
    setIntersection(set1, set2);
    printf("Set Intersection (Set1 ^ Set2):");
    printBitSet(result);
    printf(" - ");
    printSet(result);
    printf("\n");
    setComplement(set1);
    printf("Set Complement (Set1):");
    printBitSet(result);
    printf(" - ");
    printSet(result);
    printf("\n");
    setDifference(set1, set2);
    printf("Set Difference (Set1-Set2):");
    printBitSet(result);
    printf(" - ");
    printSet(result);
}
