package com.bigzhao.xml2axml.android.content;

import com.bigzhao.xml2axml.android.content.res.Resources;

/**
 * Created by Roy on 15-10-6.
 */
public class Context {
    private Resources resources = new Resources();

    public Resources getResources() {
        return resources;
    }

    public String getPackageName() {
        return "com.bighzao.xml2axml";
    }
}
