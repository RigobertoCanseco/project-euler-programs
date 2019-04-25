
function Abundants() {
    this.abundants = [];
}

Abundants.prototype.search = function(l){
    Array.from(Array(l+1).keys()).slice(1).forEach(n => {
        let a = Array.from(Array(n).keys()).slice(1).reduce((a, c) => {
                    if (n % c === 0) a+=c;
                    return a;
                }, 0);
        if(a > n)
            this.abundants.push(n);
    }, this);
    return this.abundants;
};

Abundants.prototype.sum = function(n){
    let r = [];
    this.abundants.forEach( (c, i) => {
        for(let j = i; j < this.abundants.length; j++){
        let s = (c + this.abundants[j]);
        if(s === n){
            r.push([c, this.abundants[j]])
        }
    }

}, r);
    return r;
};

const abundants = new Abundants();
let N = 28123 ;
let n = [];
let m = 0;
abundants.search(N);
//console.log(abundants.abundants);

for(let i = 1; i <= N ; i++){
    //
    if(abundants.sum(i).length === 0){
        if(m<i)
            m = i;
        n.push(i);
    }
}
//console.log(m);
//console.log(n);

console.log(n.reduce((a,c) => {return a + c}));
