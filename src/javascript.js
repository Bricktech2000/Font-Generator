const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
const fs = require('fs');


class Char{
    constructor(rows){
        this.rows = rows;
    }
    append(arr){
        for(var i = 0; i < this.rows.length; i++){
            if(i >= arr.length) arr.push('');
            arr[i] += this.rows[i];
        }
    }
}

class Font{
    constructor(charMap){
        this.charMap = charMap
    }
    gen(string){
        var ret = [];
        for(var c of string)
            this.charMap[c].append(ret);
        return ret.join('\n');
    }
}

class FontGenerator{
    constructor(font){
        var chrs = font.split('\n\n');
        var charMap = {}
        for(var chr of chrs){
            var lines = chr.split('\n');
            charMap[lines[0]] = new Char(lines.splice(1));
        }
        this.font = new Font(charMap);
    }
    gen(...params){
        return this.font.gen(...params);
    }
}

var filename = process.argv[2];
var generator;
fs.readFile(filename, 'utf8', function(err, font){
    generator = new FontGenerator(font);
});
function ask(){
    rl.question("text: ", function(string){
        console.log(generator.gen(string));
        ask();
    });
}
ask();
