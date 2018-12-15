function toggle(a) {
    if (document.getElementById(a) != null) {
        if (document.getElementById(a).getAttribute("hid") == "1") {
            deplier(a)
        } else {
            plier(a)
        }
        console.log(document.getElementById(a).getAttribute("hid"))
    }
    else {
        console.log("-1");

    }
}

function plier(a) {
    console.log("p " + a);
    if (document.getElementById(a) == null) {
    } else {
        document.getElementById(a).setAttribute("hid", "1")
        console.log(a);

    }
}

function deplier(a) {
    console.log("dp " + a);
    if (document.getElementById(a) == null) {
    } else {
        document.getElementById(a).setAttribute("hid", "0")
    }

}

function toutPlier(a) {
    console.log("tp " + a);
    var n = document.getElementById("acc" + a).value

    for (let i = 2; i < n; i++) {
        plier("a" + a + "a" + i)
    }
}

function toutDePlier(a) {
    console.log("tdp " + a);

    var n = document.getElementById("acc" + a).value

    for (let i = 1; i < n; i++) {
        deplier("a" + a + "a" + i)
    }
}