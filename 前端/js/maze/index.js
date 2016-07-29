var star = false, end = false;
var zuo = false, you = false;

window.onload = Maze;
function Maze() {
    var s = document.getElementById("s");
    s.onmouseover = function() {
    	result.innerHTML = "Start!";
        star = true;
    }

    var e = document.getElementById("e");
	var result = document.getElementById("result");

	e.onmouseover = function() {
		end = true;
		if (star == true) {
			if (end == true && zuo == true && you == false) {
				result.innerHTML = "You Won!";
			} else if (end == true && you == true && zuo == false) {
				result.innerHTML = "Don't cheat, you should start from the 'S' and move to the 'E' inside the maze!";
			}
		}
		if (star == false && end == true)
			result.innerHTML = "Don't cheat, you should start from the 'S' and move to the 'E' inside the maze!";
	}
	
	e.onmouseout = function() {
		star = false, end = false;
        zuo = false, you = false;
	}

	var l = document.getElementsByClassName("loose");
	for (var i = 0; i < l.length; ++i) {  // 碰到墙
        l[i].onmouseover = function() {
        	if (star) {
        		this.className = "changed";
        	    result.innerHTML = "You Lose!";
        	}
        }
        l[i].onmouseout = function() {
        	if (star) {
        		this.className = "loose";
        	    star = false, end = false;
                zuo = false, you = false;
        	}
        }
	}

	var z = document.getElementById("zuo"); // E左右各有一个div用来判断是否作弊
	z.onmouseover = function() {
		if (star) zuo = true;
	}

    var y = document.getElementById("you");
	y.onmouseover = function() {
		if (star) you = true;
	}
}
