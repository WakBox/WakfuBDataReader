package com.ankamagames.wakfu.client.binaryStorage;

public class AudioMarkerInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int ckx;
    protected boolean cky;
    
    public AudioMarkerInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int ZM()
    {
        return this.ckx;
    }
    
    public boolean zU()
    {
        return this.cky;
    }
    
    public void reset()
    {
        this.az = 0;
        this.ckx = 0;
        this.cky = false;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.ckx = a.getInt();
        this.cky = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eDu.getId();
    }
}