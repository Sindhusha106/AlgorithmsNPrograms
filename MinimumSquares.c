/* Paper cut into minimum number of squares 

Given a paper of size A x B. Task is to cut the paper into squares of any size. Find the minimum number of squares that can be cut from the paper.

Examples:

Input  : 13 x 29
Output : 9
Explanation : 
2 (squares of size 13x13) + 
4 (squares of size 3x3) + 
3 (squares of size 1x1)=9

Input  : 4 x 5
Output : 5
Explanation : 
1 (squares of size 4x4) + 
4 (squares of size 1x1)
*/

// Iterative Approach

#include <stdio.h>

int MinSquares(int l, int b)
{
	int count = 0, remainder = 0;
	if (l < b)
	{
	    l = l^b;
	    b = l^b;
	    l = l^b;
	}
	while (b > 0)
	{
		count += l/b;

		int remainder = l % b;
		// greater dimension is l;
		l = b;
		b = remainder;
	}
	return count;
}

void main()
{
	int l = 29, b = 65;
	printf("%d", MinSquares(l, b));
}

// Recursive Approach
#include <stdio.h>
int MinSquare(int l,int b,int count)
{
    if(l<b)
    {
        l = l^b;
        b = l^b;
        l = l^b;
    }
    if(l%b==0) return count+l/b;
    else{
    count+=l/b;
    int r=l%b;
    MinSquare(b,r,count);
    }
}

void main() {
	int l=13,b=29;
	printf("%d", MinSquare(l,b,0));
}