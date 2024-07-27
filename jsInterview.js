//1
console.log("Age: ",age);
var age = 20;
console.log("Age: ",age);
//Code execution has 2 phase memory and code phase
//compiler will store all the variables, normal functions used in code in a memory phase with undefined initialization first and as the code exectutes line by line than value gets change accordingly
//var age : undefined after crossing 3rd line it will become 20;



//2
age = 30;
console.log("Age: ",age);
var age = 50; //not work with let and const(Temporal Dead Zone)
console.log("Age: ",age);



//3
myfunc();
var myfunc = function(){
    console.log("First");
}
myfunc();
function myfunc(){
    console.log("Second");
}
myfunc();
//var myfunc = undefined , after crossing 25th line compiler will change it to => var myfunc = fn(){}
//therfore Output is : Second First First


//4
var variable = 10;
(()=>{  //this is IIFE (Immediately invoked function Expression)
    console.log(variable);
    variable = 20;
    console.log(variable);
})();
console.log(variable);
var variable = 30;


//5
vari = 10;
(()=>{ //IIFE Makes their own code local execution phase in the code phase and all its variable are inside that new memory phase once the iife function gets executed that new locally made execution phase gets removed or vanished
    foo = 100;
    console.log(vari);
    var foo = 100;
    vari = 20;
    console.log(vari);
})()

//console.log(foo); //throw error because foo is inside IIFE which is not at global level 
console.log(vari);


//6
for(var i=0; i<10; i++){
    setTimeout(()=>{console.log(i)},0)
}
for(let i=0; i<10; i++){ //because scope of let is local and that of var is global
    setTimeout(()=>{console.log(i)},0)
}


//7
var fullname = "Ashish"
var obj = {
    fullname: "Ashish Maurya",
    prop:{
        fullname: "Ashish Maurya V2",
        getFullname: function(){
            return this.fullname;
        },
    },
    getFullname: function(){
        return this.fullname;
    },

    getFullnameV2 : () => this.fullname, //because this in arrow function refers to window obj in browser

    getFullnameV3 : (function(){
        return this.fullname;
    })(),
}

console.log(obj.prop.getFullname());
console.log(obj.getFullname());
console.log(obj.getFullnameV2());
// console.log(obj.getFullnameV3()); //throw error because it is a propert not a function
console.log(obj.getFullnameV3);




//8
console.log("8th Question");
const Ashish = {
    name :"Ashish Maurya",
    sayName:function(){
        console.log(this.name);
    },
}

const Maurya =  {
    name: "Ashish Maurya V2",
    sayName: function(){
        console.log(this.name);
    },
}

// Maurya.sayName.call(Ashish)

function sayName(){
    console.log(this.name);
}
sayName(); //Undefined because context is absent
sayName.call(Maurya); //Now this is poining to Maurya Object;



//9
const maurya =  {
    name: "Ashish Maurya V2",
    sayName: function(){
        console.log(this.name);
    },
}
setTimeout(maurya.sayName,3000);
setTimeout(() => maurya.sayName(),3000);
setTimeout(maurya.sayName.bind(maurya),3000);



//Whenever we run a code a global execution context gets generated in a call stack and our code gets executed in a call stack line by line 
//Event loop keep eye on task queue and push the event from the task queue to call stack whenever any event arrives in the task queue,    Event Loop only pushes if call stack is empty   : SetTimeOut SetInterval 
//property: GES does't wait for any event (e.g) SetTimeOut
//for promises browser maintains another queue called as Microtask Queue and has more priority than task queue //fetch

console.log("A");
setTimeout(()=>{console.log("B");},3000)
console.log("C");
Promise.resolve().then(()=>{
    console.log("D");
})