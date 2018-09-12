/*A modified floydWarshall for implementation of Distance Vector 
Routing Algorithm */

//implementation of floydWarshall taken from geeks for geeks
import java.util.*; 
import java.lang.*; 
import java.io.*; 
import java.util.Scanner;

class AllPairShortestPath 
{ 
	final static int INF = 10000;
     final static int NIL=10000;
	void floydWarshall(int graph[][],int pred[][],int V) 
	{ 
		int dist[][] = new int[V][V]; 
		int i, j, k; 

		
		for (i = 0; i < V; i++) 
			for (j = 0; j < V; j++) 
				dist[i][j] = graph[i][j]; 

		
		for (k = 0; k < V; k++) 
		{ 
		
			for (i = 0; i < V; i++) 
			{ 
			
				for (j = 0; j < V; j++) 
				{ 
					
					if (dist[i][k] + dist[k][j] < dist[i][j]) 
						{
						    dist[i][j] = dist[i][k] + dist[k][j]; 
						pred[i][j]=pred[i][k];
						    
						}
				} 
			} 
		} 

		printSolution(dist,pred,V); 
	} 

	void printSolution(int dist[][],int pred[][],int V) 
	{ 
		
		System.out.println("The following is the distance vector table after the process of calculation is completed ");
		System.out.println();
		for (int i=0; i<V; ++i) 
		{ 
		    System.out.println("distance vector table for Router :  "+i+":");
		    System.out.println();
			System.out.println("TO   Distance  Next hop");
			for (int j=0; j<V; ++j) 
			{ 
	            			
					System.out.println(j+"          "+dist[i][j]+"       "+pred[i][j]); 
					
		//if outpur of pred[i][j] is 10000 it means no outgoing
		//line could be found
			} 
			System.out.println(); 
		} 
	} 


	
	public static void main(String[] args){
	    
	    Scanner sc=new Scanner(System.in);
	    int n=sc.nextInt();
	//number of vertices of graph
	    int[][]graph=new int[n][n];int[][]pred=new int[n][n];
	//graph is graph, pred keeps track of next outgoing line through which 
	//we can get to a specified router in shortest metric
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            //if there is no edge between 2 node give input of 10000
	            //here 10000 is assumed infinity
	            graph[i][j]=sc.nextInt();
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(graph[i][j]!=INF)
	            {
	                pred[i][j]=j;
	            }
	            else
	            pred[i][j]=NIL;//NIL also equals 10000 means no outgoinng line yet found
	        }
	    }
	    AllPairShortestPath a = new AllPairShortestPath(); 
	    	a.floydWarshall(graph,pred,n); 
	}
} 


