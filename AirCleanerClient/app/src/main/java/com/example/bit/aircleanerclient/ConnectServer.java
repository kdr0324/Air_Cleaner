package com.example.bit.aircleanerclient;

import android.content.Context;

import com.android.volley.RequestQueue;
import com.android.volley.toolbox.Volley;
import com.google.gson.Gson;

import org.json.JSONObject;

public class ConnectServer {
    private static ConnectServer instace;
    private static Context context;
    private RequestQueue requestQueue;
    private JSONObject jsonObject;
    private Gson gson;



    private ConnectServer(Context context){
        this.context = context;
        requestQueue = Volley.newRequestQueue(context.getApplicationContext());
        gson = new Gson();
    }

    public static synchronized ConnectServer getInstace(Context context) {
        if(instace==null){
            instace = new ConnectServer(context);
        }
        return instace;
    }

    public RequestQueue getRequestQueue() {
        return requestQueue;
    }

    public Gson getGson() {
        return gson;
    }

}
