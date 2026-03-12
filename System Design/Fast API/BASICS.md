- is a framework in python that helps in making api in python 
- is build upon the success of starlette ,
- use UVICORN as a webserver(port listener )
- helps in making api use await and async functionality of the python 

```python 
from fastapi import FastAPI  
import asyncio  
  
# Create a FastAPI application instance  
app = FastAPI()  
# Use a decorator to define a GET request route. The function is an asynchronous function and can handle time-consuming operations without blocking other requests  
@app.get("/async_items/")  
async def async_read_items():  
	await asyncio.sleep(1) # Simulate an I/O operation and pause for 1 second  
	return {"message": "FastAPI asynchronous processing example"}
```


fastAPI is fast to code , 
	- automatic input validation ( python does not have basic type checks , so we need a function that helps in checking the input is of correct data type) is closed with pydantic 
	- Auto generated document of the api you are building , based on your endpoints 
	-  Compatible with most of the machine learning libraries , also tightly coupled with most of the modern application 


---
# HTTP method

								Software types
				Dynamic 								Static
	help in two way communication               used for consuming content majorly


CRUD 
	all the interactions in any dynamic software 
	create
	read 
	update
	delete


# methods

1 GET to retrieve some information from the website
2 POST to show some information on the website
3 PUT to update some existing resource on the website
4 DELETE to remove some resource



# Basic method for showing endpoints working 


```python
from fastapi import FastAPI  
app = FastAPI()  
#app endpoint  
@app.get("/")  
def hello():  
    return {"message": "World"}  
@app.get("/about")  
def about():  
    return {"message": "About"}
```

# Path Parameters
are dynamic segment of a url that help to identify a specific resource 

```PYTHON
@app.get("/patients/{patient_id}")  
def view_patient(patient_id: str):  
    data = load_data()  
    if patient_id in  data:  
        return data[patient_id]  
    else:  
        raise HTTPException(status_code=404, detail="Patient not found")
```

# using PATH() function
- used to provide metadata
- used to help in data validation 
- used to enforce specific info about the get 
```PYTHON 
@app.get("/patients/{patient_id}")  
def view_patient(patient_id: str=Path(..., description='use it to retrieve patient data',example='P001')):  
    data = load_data()  
      
    if patient_id in  data:  
        return data[patient_id]  
    else:  
        raise HTTPException(status_code=404, detail="Patient not found")``
```
using basic description to provide more data on how to use the specific api 

![[Pasted image 20260312112257.png]]


# Query Parameter
 ki vo sorted order me bhi data dekh sakta hai 
 ki agar usko weight ke base pe dekhna hai to dekh sakta hai 
 overall ki different chizo ke basis pe 
    **Optional key value parameters given at the end of an endpoints 
    best part they are optional
	- question ? marks the starting of a query parameter
	QUERY()
	
