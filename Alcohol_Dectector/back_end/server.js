var express = require('express');
var bodyParser = require("body-parser");
var cors = require('cors');
var morgan = require('morgan');
var mysql = require('mysql2');

var app = express();
app.use(cors());
app.use(express.static('public'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

//mysql
var con = mysql.createConnection({
    host: "localhost",
    port: "3306",
    user: "root",
    password: "1234",
    insecureAuth: true,
    database: "alcoholdb"
});
con.connect(function (err) {
    if (err) throw err;
    console.log("Connected!!!")
});

//Test API
app.get("/", function (req, res) {
    res.send("Hello World");
});
//Restful API
app.get("/person", function (req, res) {
    // const id = req.params.id;
    var sql = "select * from person;";
    con.query(sql, function (err, results) {
        if (err) throw err;
        //console.log(results);
        res.send(results);
    });
});
app.get("/person/:id", function (req, res) {
    const id = req.params.id;
    var sql = "select * from person where id = "+id+";";
    con.query(sql, function (err, results) {
        if (err) throw err;
        //console.log(results);
        res.send(results);
    });
});
app.post("/person", function(req, res) {
    const {p_LName, p_MName, p_FName, p_StatusIndex, p_Status} = req.body;
    var sql = "insert into person (p_LName, p_MName, p_FName, p_StatusIndex, p_Status) values ('"+p_LName+"','"+p_MName+"','"+p_FName+"',"+p_StatusIndex+",'"+p_Status+"');";
    con.query(sql, function (err, results) {
        if (err) throw err;
        //console.log(results);
        // res.send("Add complete!!");
        // res.send(results);
        res.send("Add Complete ("+p_LName+", "+p_MName+", "+p_FName+", "+p_StatusIndex+", "+p_Status+")");
    });
});
app.put("/person/:id", function(req, res) {
    const {id} = req.params.id;
    const {p_ID, p_LName, p_MName, p_FName} = req.body;
    var sql = "update person set p_ID = '"+p_ID+"', p_LName = '"+p_LName+"', p_MName = '"+p_MName+"', p_FName = '"+p_FName+"' where ID = "+id+";";
    con.query(sql, function (err, results) {
        if (err) throw err;
        //console.log(results);
        res.send("Update complete!!");
        //res.send(results);
    });
});
app.delete("/person/:id", function(req, res) {
    const id = req.params.id;
    var sql = "delete from person where ID = "+id+";";
    con.query(sql, function (err, results) {
        if (err) throw err;
        //console.log(results);
        res.send("Delete complete!!");
        //res.send(results);
    });
});

//server
const port = 8080;
var server = app.listen(port, function () {
    var host = server.address().address;
    console.log(`Server is listening at http://${host}:${port}`)
});