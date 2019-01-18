package com.example.bit.aircleanerclient;

import android.content.Context;
import android.util.Log;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class AirState {

    private String _time;
    private float dust;
    private float temperature;
    private float humidity;

    public AirState(){
    }

//    public void getAirStateFromServer(final ConnectServer instance){
//        JsonObjectRequest request = new JsonObjectRequest(Request.Method.GET,
//                Server.mSERVER + Server.mAirState,
//                null,
//                new Response.Listener<JSONObject>() {
//                    @Override
//                    public void onResponse(JSONObject response) {
//                        try {
//                            JSONArray json = response.getJSONArray("weather");
//                            AirState[] airStates = instance.getGson().fromJson(json.toString(),AirState[].class);
//                            Log.d("[DEBUG]", "Request add" + json.toString());
//
//                            set_time(airStates[0]._time);
//                            setTemperature(airStates[0].temperature);
//                            setHumidity(airStates[0].humidity);
//
//
//
//                        } catch (Exception e) {
//
//                            e.printStackTrace();
//                        }
//                    }
//                },
//                new Response.ErrorListener() {
//                    @Override
//                    public void onErrorResponse(VolleyError error) {
//                        Log.d("[DEBUG]", "Error" + error.toString());
//                    }
//                });
//
//        instance.getRequestQueue().add(request);
//
//
//
//
//    }

    public String get_time() {
        return _time;
    }

    public void set_time(String _time) {
        this._time = _time;
    }

    public float getDust() {
        return dust;
    }

    public void setDust(float dust) {
        this.dust = dust;
    }

    public float getTemperature() {
        return temperature;
    }

    public void setTemperature(float temperature) {
        this.temperature = temperature;
    }

    public float getHumidity() {
        return humidity;
    }

    public void setHumidity(float humidity) {
        this.humidity = humidity;
    }
}
