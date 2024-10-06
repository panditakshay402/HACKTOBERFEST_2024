from flask import Flask, render_template, request
import pickle

app = Flask(__name__)
#load the model
model = pickle.load(open('trained_model.sav','rb'))

@app.route('/')
def home():
    result = ''
    return render_template('index.html',**locals())


@app.route('/predict', methods=['POST', 'GET'])