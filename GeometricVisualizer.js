let W = 3200;
let H = 1600;
let stepSize = 50;
let SWeight = 2;
let displayNumbers = 1;
let fontSize = 22;

/*
pt(x, y, col);
segment(x1, y1, x2, y2, color);
vector(x1, y1, vx, vy, color);
circle(x, y, r, color);
rec(x1, y1, x2, y2, color);
tri(x1, y1, x2, y2, x3, y3, color);
*/

function drawShapes() {
    convexHull();
    //segment(-1,1,7,5);
    //Line(2,1);
    //Line(-0.2, 10);
}

function convexHull() {
    var pts = []
    pts.push({ x: -1, y: -1 });
    pts.push({ x: -2, y: -2 });
    pts.push({ x: -4, y: 1 });
    pts.push({ x: -1, y: 3 });
    pts.push({ x: 1, y: 4 });
    pts.push({ x: 4, y: 3 });
    pts.push({ x: -3, y: 4 });
    pts.push({ x: 2, y: 2 });
    pts.push({ x: -3, y: 2 });
    pts.push({ x: 3, y: -1 });
    pts.push({ x: 1, y: -2 });
    pts.push({ x: 1, y: 1 });

    var chull = convexhull.makeHull(pts);
    for (let i = 0; i < pts.length; ++i)
        pt(pts[i].x, pts[i].y);
    polygon(chull);
}

function polygon(points) {
    points.push(points[0]);
    for (let i = 1; i < points.length; ++i)
        segment(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y, 'brown');
}

function pt(x, y, col) {
    col = col || 'rgb(199,0,223)';
    x *= stepSize; y *= -stepSize;
    stroke(col);
    strokeWeight(10);
    beginShape(POINTS);
    vertex(x, y);
    endShape();
    strokeWeight(SWeight);
}

function rec(x1, y1, x2, y2, col) {
    col = col || 'blue';
    x1 *= stepSize; x2 *= stepSize; y1 *= -stepSize; y2 *= -stepSize;
    stroke(col);
    rect(x1, y1, x2 - x1, y2 - y1);
}

function tri(x1, y1, x2, y2, x3, y3, col) {
    col = col || 'orange';
    pt(x1, y1, col);
    pt(x2, y2, col);
    pt(x3, y3, col);
    x1 *= stepSize; x2 *= stepSize; x3 *= stepSize; y1 *= -stepSize; y2 *= -stepSize; y3 *= -stepSize;
    stroke(col);
    triangle(x1, y1, x2, y2, x3, y3);
}

function vector(x1, y1, x2, y2, col) {
    col = col || 'rgb(0,161,211)';
    pt(x1, y1, col);
    x2 += x1;
    y2 += y1;
    x1 *= stepSize; x2 *= stepSize; y1 *= -stepSize; y2 *= -stepSize;
    stroke(col);
    line(x1, y1, x2, y2);
    line(x2 - stepSize / 8, y2 - stepSize / 8, x2 + stepSize / 8, y2 + stepSize / 8);
    line(x2 - stepSize / 8, y2 + stepSize / 8, x2 + stepSize / 8, y2 - stepSize / 8);
}

function Line(m, b, col) {
    col = col || 'green';
    let x1 = -200, x2 = 200;
    segment(x1, m * x1 + b, x2, m * x2 + b, col);
}

function segment(x1, y1, x2, y2, col) {
    col = col || 'red';
    pt(x1, y1, col);
    pt(x2, y2, col);
    x1 *= stepSize; x2 *= stepSize; y1 *= -stepSize; y2 *= -stepSize;
    stroke(col);
    line(x1, y1, x2, y2);
}

function circle(x, y, r, col) {
    col = col || 'green';
    pt(x, y, col);
    x *= stepSize; y *= -stepSize; r *= 2 * stepSize;
    stroke(col);
    ellipse(x, y, r);
}

function grid() {
    for (let i = -H / 2; i <= H / 2; i += stepSize) {
        if (!i) stroke(0);
        else stroke(230);
        line(-W / 2, i, W / 2, i);
    }
    for (let i = -W / 2; i <= W / 2; i += stepSize) {
        if (!i) stroke(0);
        else stroke(230);
        line(i, -H / 2, i, H / 2);
    }
    stroke(0);
    line(-W / 2, 0, W / 2, 0);
}

function gridNumbering() {
    for (let i = -W / 2; i <= W / 2; i += stepSize)
        text(i / stepSize + "", i, 0);
    for (let i = -H / 2; i <= H / 2; i += stepSize)
        text(-i / stepSize + "", 0, i);
}

function draw() {
    background(255);
    translate(W / 2, H / 2);
    noFill();
    strokeWeight(SWeight);
    textFont('Arial', fontSize);
    grid();
    if (displayNumbers)
        gridNumbering();
    drawShapes();
}

function setup() {
    createCanvas(W, H);
}