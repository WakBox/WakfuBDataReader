package com.ankamagames.wakfu.client.binaryStorage;

public class DialogBinaryData implements dEZ {
    protected int az;
    protected String aZr;
    protected MH[] bxi;
    
    public DialogBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public String vS()
    {
        return this.aZr;
    }
    
    public MH[] HW()
    {
        return this.bxi;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aZr = null;
        this.bxi = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aZr = a.clg().intern();
        int i = a.getInt();
        this.bxi = new MH[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.bxi[i0] = new MH();
            this.bxi[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDQ.getId();
    }
}