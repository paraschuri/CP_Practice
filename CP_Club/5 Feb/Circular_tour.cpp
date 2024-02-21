int tour(petrolPump p[],int n)
{
    //Your code here
    int total_gas=0,total_cost=0;
    int curr_gas=0, starting_point=0;
    for(int i=0;i<n;i++){
        total_gas+=p[i].petrol;
        total_cost+=p[i].distance;
        curr_gas+=p[i].petrol-p[i].distance;
        if(curr_gas<0){
            starting_point=i+1;
            curr_gas=0;
        }
    }
    return (total_gas<total_cost)?-1:starting_point;  
}