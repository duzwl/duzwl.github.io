var score = 0;
var start = false;
var Score;
var moles;
var time;
var index;

window.onload = function() {
	creatmoles();
	beclicked();
	startt();
}

function creatmoles() {   // 创建地鼠
	moles = document.getElementById("moles");
	var oFragment = document.createDocumentFragment();
	for(var i = 0; i < 60; i++) {
	 	var r = document.createElement("div");
	 	r.className = "newdiv";
	 	oFragment.appendChild(r);
	}
	moles.appendChild(oFragment);
}

function startt() {   // 开始游戏
	Score = document.getElementById("scorenum");
	moles = document.getElementById("moles");
	var start_stop = document.getElementById("start-stop");

	start_stop.onclick= function() {
		
		if (start == false) {  // 最开始时按下button
			start = true;
			score = 0, Score.innerHTML = score;
			document.getElementById("timenum").innerHTML = 30;
			document.getElementById("state").innerHTML = "Playing";
			time = setInterval(go, 1000);
			index = Math.floor(Math.random()*60);
			moles.childNodes[index].className = "active";
		} else {             // 结束游戏
			clearInterval(time);
			var text = "Game Over.\nYour score is: ";
		    text += score;
		    alert(text);
		    start = false, score = 0;
		    Score.innerHTML = score;
			document.getElementById("timenum").innerHTML = 0;
			document.getElementById("state").innerHTML = "Game Over";
			moles.childNodes[index].className = "newdiv";
		}
	}
}
function go() {
	Score = document.getElementById("scorenum");
	moles = document.getElementById("moles");
	var tmp = document.getElementById("timenum").innerHTML;
	tmp--;
	document.getElementById("timenum").innerHTML = tmp;

	if (start && tmp == 0) {   // 剩余时间为0，结束游戏
		clearInterval(time);
		var text = "Game Over.\nYour score is: ";
		text += score;
		alert(text);
		document.getElementById("state").innerHTML = "Game Over";
		start = false;
		moles.childNodes[index].className = "newdiv";
	}

}

function beclicked() {   // 地鼠被敲击
	Score = document.getElementById("scorenum");
	moles = document.getElementById("moles");
	var m = moles.childNodes;

    for (var i = 0; i < m.length; ++i) {
    	m[i].onclick = function() {
    		if (start) {
    			var classname = this.className;
	 			if (classname == "active") {
	 				score++;
	 				this.className = "newdiv";
	 			    index = Math.floor(Math.random()*60);
				    moles.childNodes[index].className = "active";
	 			} else {
	 				score--;
	 				moles.childNodes[index].className = "newdiv";
	 				index = Math.floor(Math.random()*60);
				    moles.childNodes[index].className = "active";
	 			}
	 			Score.innerHTML = score;
    		}
    	}
    }
    
}
