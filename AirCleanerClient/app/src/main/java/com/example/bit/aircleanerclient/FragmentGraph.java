package com.example.bit.aircleanerclient;

import android.graphics.Color;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RelativeLayout;

import com.github.mikephil.charting.charts.LineChart;


public class FragmentGraph extends Fragment {
    public FragmentGraph(){
        Log.d("[DEBUG]", "CALL FragmentGraph");
    }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        RelativeLayout layout = (RelativeLayout) inflater
                .inflate(R.layout.view_pager_item_graph, container, false);

        LineChart chart = (LineChart) layout.findViewById(R.id.chart);



        return layout;
    }
}
