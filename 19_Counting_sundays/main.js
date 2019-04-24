function calendary(){
  let m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  let date = [1900, 0, 1, 1];
  let c = 0;

  while(date[0] < 2001){
      if(date[3] === 7 && date[2] === 1)
        c++;
      date[2]++;
      if(date[3] === 7)
        date[3] = 1;
      else
        date[3]++;

      if(date[1] === 11 && date[2] === 31){
        date[0]++;
        date[1] = 0;
        date[2] = 1;
        if(date[0] % 4 == 0)
          m[1] = 29;
        else m[1] = 28;
      }else if(date[2] === m[date[1]]){
        date[2] = 1;
        date[1]++;
      }
  }
  return c - 1;
}

console.log(calendary());
