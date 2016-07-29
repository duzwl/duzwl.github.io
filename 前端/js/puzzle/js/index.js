var curPosition = 15;
var str = false;   // 开始按钮
var anotherbg = false;    // 记录换背景图
var m = 1;     // 记录选择的难度
var t = 9999;   // 剩余时间
var clock;

window.onload = function() {
    start();
    won();
    reset();
    onClick();
    changebg();
    choosemode();
}

function start() {  // 开始游戏，打乱拼图
    var bt = document.getElementById("bt1");
    bt.onclick = function() {
        if (!str) {
            clock = setInterval(time, 1000);
            str = true;
            var t = parseInt(Math.random()*16);
            var tempf = "";   // 临时id
            var tempt = "";
            var classf;    // 临时id对应的对象
            var classt;
            var temp;
            for (var i = 0; i < 600; ++i) {
                while (1) {
                	t = parseInt(Math.random()*16);
                	if (curPosition == 3 && (t == 2 || t == 7)) break;
                	if (curPosition == 4 && (t == 0 || t == 5 || t == 8)) break;
                	if (curPosition == 7 && (t == 6 || t == 3 || t == 11)) break;
                	if (curPosition == 8 && (t == 9 || t == 4 || t == 12)) break;
                	if (curPosition == 11 && (t == 10 || t == 15 || t == 7)) break;
                	if (curPosition == 12 && (t == 13 || t == 8)) break;
                	if (curPosition == 0 && (t == 1 || t == 4)) break;
                	if (curPosition == 1 && (t == 0 || t == 2 || t == 5)) break;
                	if (curPosition == 2 && (t == 1 || t == 3 || t == 6)) break;
                	if (curPosition == 5 && (t == 4 || t == 6 || t == 1 || t == 9)) break;
                	if (curPosition == 6 && (t == 5 || t == 7 || t == 2 || t == 10)) break;
                	if (curPosition == 9 && (t == 8 || t == 10 || t == 5 || t == 13)) break;
                	if (curPosition == 10 && (t == 9 || t == 11 || t == 6 || t == 14)) break;
                	if (curPosition == 13 && (t == 12 || t == 14 || t == 9)) break;
                	if (curPosition == 14 && (t == 13 || t == 15 || t == 10)) break;
                	if (curPosition == 15 && (t == 14 || t == 11)) break;
                }
                tempt = "d"+curPosition.toString();
                tempf = "d"+t.toString();
                classf = document.getElementById(tempf);
                classt = document.getElementById(tempt);
                temp = classf.className;
                classf.className = classt.className;
                classt.className = temp;
                curPosition = t;
            }
        }
    }
}

function won() {   // 当d0与c0...相对应时即获胜
    if (str == true) {
        var all = document.getElementById("all");
        var w = true;
        var s = "";
        for (var i = 0; i < all.length; ++i) {
            s = "c"+i.toString();
            if (all[i].className != s) {
                w = false;
                break;
            }
        }

        if (w == true) {
            alert("You won!");
            str = false;
            curPosition = 15;
            var all = document.getElementsByTagName("div");
            for (var i = 1; i < 17; ++i) {
                if (anotherbg == true) all[i].className = "c"+(i-1).toString()+"c";
                else all[i].className = "c"+(i-1).toString();
            }
            if (m == 1) t = 9999;
            else if (m == 2) t = 360;
            else t = 180;
            document.getElementById("leftt").innerHTML = t;
            clearInterval(clock);
        }
    } 
}

function onClick() {    // 图片被点击
    var all = document.getElementsByTagName("div");
    var s = "";
    var tempf = "";   // 临时id
    var tempt = "";
    var classf;     // 临时id对应的类
    var classt;
    for (var i = 1; i < all.length; ++i) {
        all[i].onclick = function() {
            if (str) {
                s = this.id.substring(1);
                if (s == (curPosition-1).toString() || s == (curPosition+1).toString()
                || s == (curPosition+4).toString() || s == (curPosition-4).toString()) {
                    tempt = "d"+curPosition.toString();
                    tempf = "d"+s.toString();
                    classf = document.getElementById(tempf);
                    classt = document.getElementById(tempt);
                    temp = classf.className;
                    classf.className = classt.className;
                    classt.className = temp;
                    curPosition = parseInt(s);
                }
            } 
        }
    }
}

function reset() {    // 重新开始游戏
    var bt2 = document.getElementById("bt2");
    bt2.onclick = function() {
        if (str) {
            str = false;
            curPosition = 15;
            var all = document.getElementsByTagName("div");
            for (var i = 1; i < 17; ++i) {
                if (anotherbg == true) all[i].className = "c"+(i-1).toString()+"c";
                else all[i].className = "c"+(i-1).toString();
            }
            if (m == 1) t = 9999;
            else if (m == 2) t = 360;
            else t = 180;
            document.getElementById("leftt").innerHTML = t;
            clearInterval(clock);
        }
    }
}

function changebg() {
    var bg1 = document.getElementById("bg1");
    bg1.onclick = function() {
        if (!str) {
            if (anotherbg == false) {
                anotherbg = true;
                bg1.className = "bg11";
            } else {
                anotherbg = false;
                bg1.className = "bg1c";
            }

            if (anotherbg == true) {
                var all = document.getElementsByTagName("div");
                for (var i = 1; i < 17; ++i) {
                    all[i].className += "c";
                }
            } else {
                var all = document.getElementsByTagName("div");
                for (var i = 1; i < 17; ++i) {
                    all[i].className = "c"+(i-1).toString();
                }
            }
        }
    }
}

function choosemode() {
    var mode1 = document.getElementById("mode1");
    mode1.onclick = function() {
        if (!str) {
            if (m == 2) document.getElementById("mode2").className = "bg1c";
            if (m == 3) document.getElementById("mode3").className = "bg1c";
            m = 1;
            this.className = "bg11";
            t = 9999;
            document.getElementById("leftt").innerHTML = t;
        }
    }

    var mode2 = document.getElementById("mode2");
    mode2.onclick = function() {
        if (!str) {
            if (m == 1) document.getElementById("mode1").className = "bg1c";
            if (m == 3) document.getElementById("mode3").className = "bg1c";
            m = 2;
            this.className = "bg11";
            t = 360;
            document.getElementById("leftt").innerHTML = t;
        }
    }

    var mode3 = document.getElementById("mode3");
    mode3.onclick = function() {
        if (!str) {
            if (m == 2) document.getElementById("mode2").className = "bg1c";
            if (m == 1) document.getElementById("mode1").className = "bg1c";
            m = 3;
            this.className = "bg11";
            t = 180;
            document.getElementById("leftt").innerHTML = t;
        }
    }
}

function time() {
    if (str) {
        t--;
        document.getElementById("leftt").innerHTML = t;

        if (t <= 0) {
            alert("You lose!");
            str = false;
            curPosition = 15;
            var all = document.getElementsByTagName("div");
            for (var i = 1; i < 17; ++i) {
                if (anotherbg == true) all[i].className = "c"+(i-1).toString()+"c";
                else all[i].className = "c"+(i-1).toString();
            }
            if (m == 1) t = 9999;
            else if (m == 2) t = 360;
            else t = 180;
            document.getElementById("leftt").innerHTML = t;
            clearInterval(clock);
        }
        
    }
}
