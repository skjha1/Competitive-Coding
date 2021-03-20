string reverseWord(string str){
  int i,j,temp;
    for (j=0;str[j]!='\0';j++){
    }
    j--;
  for (i=0;i<j;i++,j--){
        trmp=str[i];
        str[i]=str[j];
        str[j]=temp;
  }
  return str;
}


-----------------------------------------------------------------------------------

string reverseWord(string str){
  int i=0;
  int j=str.size()-1;
  while (i<j)
  {
    swap(str[i],str[j]);
    i++;
    j--;
  }
  return str;
}
