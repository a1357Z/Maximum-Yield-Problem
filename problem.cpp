#include<bits/stdc++.h>
using namespace std;

vector<double> finalFraction;
double maxWeight;

void buildAnswer(int index, vector<double>& stocks, vector<double>& percentE, vector<double>& percentAlpha, 
    vector<double>& percentDelta, double x, double y, double z, vector<double> &fractionArray){
    int n = stocks.size();

    // this can work for stocks upto length 7, but it gives less accurate answer --> using steps of length 0.5
    vector<double> fractions = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

    // this can work for stocks upto length 6, it gives more accurate answer --> using steps of length 0.05
    // vector<double> fractions = {0.00, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, 0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 1.00};
    
    if(index == n){
        // compute if the conditions are valid for this fractionArray and update the answer

        // % of vitamin E >= x; % of alpha <= y; % of delta <= z
        double vitaminEPercent, alphaPercent, deltaPercent, totalWeight = 0, vitaminEWeight = 0, alphaWeight = 0, deltaWeight = 0;
        for(int i=0;i<n;i++){
            totalWeight += stocks[i]*fractionArray[i];
            vitaminEWeight += stocks[i]*fractionArray[i]*(percentE[i]/100);
            alphaWeight += stocks[i]*fractionArray[i]*(percentE[i]/100)*(percentAlpha[i]/100);
            deltaWeight += stocks[i]*fractionArray[i]*(percentE[i]/100)*(percentDelta[i]/100);
        }

        vitaminEPercent = (vitaminEWeight*100)/totalWeight;
        alphaPercent = (alphaWeight*100)/totalWeight;
        deltaPercent = (deltaWeight*100)/totalWeight;
        

        if(vitaminEPercent >= x && alphaPercent <= y && deltaPercent <= z && totalWeight > maxWeight){
            finalFraction = fractionArray;
        }
        return;
    }

    for(auto f: fractions){
        fractionArray[index] = f;
        buildAnswer(index+1, stocks, percentE, percentAlpha, percentDelta, x, y, z, fractionArray);
    }

    fractionArray[index] = 0;
}

int main(){
    int n;
    cout<<"enter the number of stocks "<<endl;
    cin>>n;

    maxWeight = 0;

    vector<double> stocks(n), percentE(n), percentAlpha(n), percentDelta(n);
    double x, y, z;

    cout<<"enter the weights of stocks "<<endl;
    for(int i=0;i<n;i++){
        cin>>stocks[i];
    }

    cout<<"enter the percentage of vitamin E in each cut "<<endl;
    for(int i=0;i<n;i++){
        cin>>percentE[i];
    }

    cout<<"enter the percentage of alpha in each cut "<<endl;
    for(int i=0;i<n;i++){
        cin>>percentAlpha[i];
    }

    cout<<"enter the percentage of delta in each cut "<<endl;
    for(int i=0;i<n;i++){
        cin>>percentDelta[i];
    }

    cout<<"enter minimum percent of vitamin E in the final mixture"<<endl;
    cin>>x;

    cout<<"enter minimum percent of alpha in the final mixture"<<endl;
    cin>>y;

    cout<<"enter minimum percent of delta in the final mixture"<<endl;
    cin>>z;

    vector<double> fractionArray(n);

    buildAnswer(0, stocks, percentE, percentAlpha, percentDelta, x, y, z, fractionArray);

    double vitaminEPercent, alphaPercent, deltaPercent, totalWeight = 0, vitaminEWeight = 0, alphaWeight = 0, deltaWeight = 0;
    for(int i=0;i<n;i++){
        totalWeight += stocks[i]*finalFraction[i];
        vitaminEWeight += stocks[i]*finalFraction[i]*(percentE[i]/100);
        alphaWeight += stocks[i]*finalFraction[i]*(percentE[i]/100)*(percentAlpha[i]/100);
        deltaWeight += stocks[i]*finalFraction[i]*(percentE[i]/100)*(percentDelta[i]/100);
    }

    vitaminEPercent = (vitaminEWeight*100)/totalWeight;
    alphaPercent = (alphaWeight*100)/totalWeight;
    deltaPercent = (deltaWeight*100)/totalWeight;

    cout<<"vitaminEPercent: "<<vitaminEPercent<<endl;
    cout<<"alphaPercent: "<<alphaPercent<<endl;
    cout<<"deltaPercent: "<<deltaPercent<<endl;
    cout<<"totalWeight: "<<totalWeight<<endl;

    cout<<"weights of stocks to choose: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"stock no: "<<i+1<<", weight: "<<finalFraction[i]*stocks[i]<<endl;
    }
}