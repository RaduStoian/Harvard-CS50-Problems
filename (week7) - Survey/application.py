import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    # spits error page if name not entered
    if not request.form.get("name"):
        return render_template("error.html", message="You did not input a name")
    else:
        # appends form details into csv row
        with open("survey.csv", "a", newline='') as file:
            writer = csv.writer(file, delimiter=" ")
            writer.writerow([request.form.get("name")])

    # redirect user to /sheet
        return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():

    lineList = []

    # read through survey.csv
    with open("survey.csv", "r", newline="") as file:
        reader = csv.reader(file)

        for line in reader:
            lineList.append(str(line).replace("'", "").replace("[", "").replace("]", ""))

    # display submissions in an html table
    return render_template("success.html", lineList=lineList)
