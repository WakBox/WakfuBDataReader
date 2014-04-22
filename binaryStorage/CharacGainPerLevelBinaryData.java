package com.ankamagames.wakfu.client.binaryStorage;

public class CharacGainPerLevelBinaryData implements dEZ {
    protected short aZG;
    protected cXr hIh;
    
    public CharacGainPerLevelBinaryData()
    {
        super();
    }
    
    public short vV()
    {
        int i = this.aZG;
        return (short)i;
    }
    
    public cXr ckC()
    {
        return this.hIh;
    }
    
    public void reset()
    {
        this.aZG = (short)0;
        this.hIh = null;
    }
    
    public void a(ceb a)
    {
        int i = a.getShort();
        this.aZG = (short)i;
        int i0 = a.getInt();
        this.hIh = new cXr(i0);
        int i1 = 0;
        while(i1 < i0)
        {
            int i2 = a.get();
            float f = a.getFloat();
            this.hIh.b((byte)i2, f);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDF.getId();
    }
}