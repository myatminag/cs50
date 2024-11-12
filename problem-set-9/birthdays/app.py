import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

def is_valid_date(month, day):
    month_days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    return (1 <= month-1 <= 12 and 1 <= day <= month_days[month-1])

def validate_form_data(name, month, day):
    if not name or not month or not day:
        message = 'Please provide a value for'
        if not name:
            message += ' "name"'
        if not month:
            message += ' "month"'
        if not day:
            message += ' "day"'
        if not year:
            message += ' "year"'
        return message

    try:
        month = int(month)
    except ValueError:
        message = 'Invalid month value'
        return message
    try:
        day = int(day)
    except ValueError:
        message = 'Invalid day value'
        return message
    try:
        year = int(year)
    except ValueError:
        message = 'Invalid year value'

    if not is_valid_date(month, day):
        message = f'Provided date "{month}/{day}" is not valid'
        return message

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        year = request.form.get("year")

        # TODO: Add the user's entry into the database
        db.execute("INSERT INTO birthdays (name, name, day, month, year) VALUES (?, ?, ?, ?, ?)", name, day, month, year)
        return redirect("/")
    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays=birthdays)


