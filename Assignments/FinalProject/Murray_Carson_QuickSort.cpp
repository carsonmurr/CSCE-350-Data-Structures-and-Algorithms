//Written by Carson Murray Copyright 2022 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <bits/stdc++.h> 
#include <fstream>
#include <sstream>

int partition(double input[], int start, int end)
{
 
    int pivot = input[start];
 
    int counter = 0;
    for (int i = start + 1; i <= end; i++) {
        if (input[i] <= pivot)
            counter++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + counter;
    std::swap(input[pivotIndex], input[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (input[i] <= pivot) {
            i++;
        }
 
        while (input[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(input[i++], input[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(double input[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(input, start, end);
 
    // Sorting the left part
    quickSort(input, start, p - 1);
 
    // Sorting the right part
    quickSort(input, p + 1, end);
}

void createSorted(double input[], int size, std::string outputFile) {
  std::fstream fout;

  // fout.open("test.txt", std::ios::out | std::ios::app);
  fout.open(outputFile, std::ios::out | std::ios::app);  // creates output file with sorted array

for(int i=0; i < size-1; ++i) {
  fout << input[i] << " ";
}
fout << input[size-1] <<"\n";
}

void createTime(double time, std::string outputFile) {
  std::fstream fout;
  fout.open(outputFile, std::ios::out | std::ios::app);  // writes execution time to txt file 
  fout << time << "\n";
}

std::vector<std::vector<std::string>> read(std::vector<std::vector<std::string>> content, 
                                            std::vector<std::string> row, 
                                            std::string line, 
                                            std::string word,
                                            std::string inputFile) {
  // std::fstream file ("input.txt", std::ios::in);
  std::fstream file (inputFile, std::ios::in);  //  reads in input file 
  if(file.is_open()) {
    while(getline(file, line)) {
    row.clear();
  
    std::stringstream str(line);
  
    while(getline(str, word, ' '))
      row.push_back(word);

    content.push_back(row);
    }
  } else
      std::cout<<"Could not open the file\n";

  return content;
}

int main (int argc, char* argv[]) {
  std::vector<std::vector<std::string>> content;
  std::vector<std::string> row;
  std::string line, word;

  
  content = read(content, row, line, word, argv[1]);  // reads in data

  double temp = 0.0;
  double input_arr[content[0].size()];  // initializes an array to be sorted

  for(int j=0;j<content[0].size();++j) {  // assigns the values read in from txt file into array
    temp = std::stod(content[0][j]);
    input_arr[j] = temp;
  }

  std::cout<<"Input:" << std::endl;;
  int size = sizeof(input_arr)/sizeof(input_arr[0]);
  // std::cout<< "size: " << size << std::endl;
  for (int i=0; i < size; ++i) {
    std::cout << input_arr[i] << ", ";
  }
  std::cout<<"\nRunning QuickSort..."<<std::endl;

  clock_t start, end;
  start = clock();  // starts timer

  quickSort(input_arr, 0, size-1);

  end = clock();  // ends timer

  double elapsed_time = std::fabs(((end-start * 1000.0)) / double(CLOCKS_PER_SEC));  // calculates elapsed time

  std::cout << "Output: " << std::endl;
  for (int i=0; i < size; ++i) {
    std::cout << input_arr[i] << ", ";
  }
  std::cout << std::endl;

  std::cout << "Time taken to complete: " << std::fixed << elapsed_time << std::setprecision(5) << "ms" << std::endl;

  createSorted(input_arr, size, argv[2]);  // writes array value to a txt file
  createTime(elapsed_time, argv[3]);  // writes execution time to a txt file

}